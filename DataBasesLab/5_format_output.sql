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

select city, count(*) as "No. of salesman" from salesman group by city
order by "No. of salesman"

select count(*) as total ,count(distinct(emp_lname))as unq from emp_details

select emp_lname,emp_dept, count(*) as cnt from emp_details group by emp_dept,emp_lname having count(*)<>1

select city, count(*),sum(commission) from salesman group by city order by sum desc limit 1 offset 2