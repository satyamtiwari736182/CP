SELECT AVG (purch_amt) 
FROM orders;

SELECT SUM (purch_amt) 
FROM orders;


SELECT COUNT (DISTINCT salesman_id) 
FROM orders;

SELECT COUNT(*) 
FROM customer;

SELECT COUNT (ALL grade) 
FROM customer;

SELECT MAX (purch_amt) 
FROM orders;

SELECT MIN(purch_amt) 
FROM orders;

SELECT city,MAX(grade) 
FROM customer 
GROUP BY city;

SELECT customer_id,MAX(purch_amt) 
FROM orders 
GROUP BY customer_id;

SELECT customer_id,ord_date,MAX(purch_amt) 
FROM orders 
GROUP BY customer_id,ord_date;

SELECT customer_id,ord_date,MAX(purch_amt) 
FROM orders 
GROUP BY customer_id,ord_date 
HAVING MAX(purch_amt)>2000.00;

SELECT customer_id,ord_date,MAX(purch_amt) 
FROM orders 
GROUP BY customer_id,ord_date 
HAVING MAX(purch_amt) BETWEEN 2000 AND 6000;

SELECT customer_id,ord_date,MAX(purch_amt) 
FROM orders 
GROUP BY customer_id,ord_date 
HAVING MAX(purch_amt) IN(2000 ,3000,5760, 6000);

SELECT customer_id,MAX(purch_amt) 
FROM orders 
WHERE customer_id BETWEEN 3002 and 3007 
GROUP BY customer_id;

SELECT customer_id,MAX(purch_amt) 
FROM orders 
WHERE customer_id BETWEEN 3002 and 3007 
GROUP BY customer_id 
HAVING MAX(purch_amt)>1000;

SELECT salesman_id,MAX(purch_amt) 
FROM orders 
GROUP BY salesman_id 
HAVING salesman_id BETWEEN 5003 AND 5008;

SELECT COUNT(*) 
FROM orders 
WHERE ord_date='2012-08-17';

SELECT COUNT(*) 
FROM salesman 
WHERE city IS NOT NULL;

SELECT ord_date,salesman_id,COUNT(*) 
FROM orders 
GROUP BY ord_date,salesman_id;

SELECT AVG(pro_price) AS "Average Price" 
   FROM item_mast;

SELECT COUNT(*) AS "Number of Products" 
  FROM item_mast 
    WHERE pro_price >= 350;

SELECT AVG(pro_price) AS "Average Price", 
       pro_com AS "Company ID"
    FROM item_mast
GROUP BY pro_com;

SELECT SUM(dpt_allotment) 
FROM emp_department;

SELECT emp_dept, COUNT(*)
  FROM emp_details
  GROUP BY emp_dept;
