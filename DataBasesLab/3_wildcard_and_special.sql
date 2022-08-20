SELECT * 
FROM salesman 
WHERE city = 'Paris' OR city = 'Rome';

SELECT * 
FROM salesman 
WHERE city IN('Paris','Rome');

SELECT * 
FROM salesman 
WHERE city NOT IN('Paris','Rome');

SELECT * 
FROM customer 
WHERE customer_id IN (3007,3008,3009);

SELECT * 
FROM salesman 
WHERE commission BETWEEN 0.12 AND 0.14;

SELECT * 
FROM orders 
WHERE (purch_amt BETWEEN 500 AND 4000) 
AND NOT purch_amt IN(948.50,1983.43);

SELECT *
FROM salesman
WHERE name BETWEEN 'A' and 'L';

SELECT *
FROM salesman
WHERE name NOT BETWEEN 'A' and 'L';

SELECT *
FROM customer
WHERE cust_name LIKE 'B%';

SELECT *
FROM customer
WHERE cust_name LIKE '%n';

SELECT *
FROM salesman
WHERE name LIKE 'N__l%';

SELECT *
FROM testtable
WHERE col1 LIKE '%/_%' ESCAPE '/';

SELECT *
FROM testtable
WHERE col1 NOT LIKE '%/_%' ESCAPE '/';

SELECT *
FROM testtable
WHERE col1 NOT LIKE '%//%' ESCAPE '/';

SELECT *
FROM testtable
WHERE col1 LIKE '%/_//%' ESCAPE '/';

SELECT *
FROM testtable
WHERE col1 NOT LIKE '%/_//%' ESCAPE '/';

SELECT *
FROM testtable
WHERE col1 LIKE '%/%%' ESCAPE'/';

SELECT *
FROM testtable
WHERE col1 NOT LIKE '%/%%' ESCAPE'/';

SELECT *
FROM customer
WHERE grade IS NULL;

SELECT *
FROM customer
WHERE grade IS NOT NULL;

SELECT * 
 FROM emp_details
  WHERE emp_lname LIKE 'D%'; 
