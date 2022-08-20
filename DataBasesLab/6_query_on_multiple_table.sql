SELECT customer.cust_name,
salesman.name, salesman.city
FROM salesman, customer
WHERE salesman.city = customer.city;

SELECT customer.cust_name, salesman.name
FROM customer,salesman
WHERE salesman.salesman_id = customer.salesman_id;

SELECT ord_no, cust_name, orders.customer_id, orders.salesman_id
FROM salesman, customer, orders
WHERE customer.city <> salesman.city
AND orders.customer_id = customer.customer_id
AND orders.salesman_id = salesman.salesman_id;

SELECT customer.cust_name AS "Customer",
customer.grade AS "Grade",orders.ord_no AS "Order No."
FROM orders, salesman, customer
WHERE orders.customer_id = customer.customer_id
AND orders.salesman_id = salesman.salesman_id
AND salesman.city IS NOT NULL
AND customer.grade IS NOT NULL;


SELECT customer.cust_name AS "Customer",
customer.city AS "City",
salesman.name AS "Salesman",
salesman.commission
FROM customer,salesman
WHERE customer.salesman_id = salesman.salesman_id
AND salesman.commission
BETWEEN .12 AND .14;

SELECT ord_no, cust_name, commission AS "Commission%",
purch_amt*commission AS "Commission"
FROM salesman,orders,customer
WHERE orders.customer_id = customer.customer_id
AND orders.salesman_id = salesman.salesman_id
AND customer.grade>=200;

SELECT *
FROM customer a,orders  b 
WHERE a.customer_id=b.customer_id 
AND b.ord_date='2012-10-05';
