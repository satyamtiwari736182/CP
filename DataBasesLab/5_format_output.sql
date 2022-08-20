SELECT salesman_id,name,city,'%',commission*100 
FROM salesman;

SELECT ' For',ord_date,',there are', 
COUNT (ord_no),'orders.' 
FROM orders 
GROUP BY ord_date;

SELECT * 
FROM orders 
ORDER BY ord_no;

SELECT * 
FROM orders 
ORDER BY ord_date DESC;

SELECT * 
FROM orders 
ORDER BY ord_date, purch_amt DESC;

SELECT cust_name,city,grade 
FROM customer 
ORDER BY customer_id;

SELECT cust_name,city,grade 
FROM customer 
ORDER BY customer_id;

SELECT salesman_id,ord_date,MAX(purch_amt) 
FROM orders 
GROUP BY salesman_id,ord_date 
ORDER BY salesman_id,ord_date;

SELECT customer_id, COUNT(DISTINCT ord_no), 
MAX(purch_amt) 
FROM orders 
GROUP BY customer_id 
ORDER BY 2 DESC;

SELECT ord_date, SUM(purch_amt), 
SUM(purch_amt)*.15 
FROM orders 
GROUP BY ord_date 
ORDER BY ord_date;

