SELECT * 
FROM customer 
WHERE grade > 100;

SELECT * 
FROM customer 
WHERE city = 'New York' AND grade>100;

SELECT * 
FROM customer 
WHERE city = 'New York' OR grade>100;

SELECT * 
FROM customer 
WHERE city = 'New York' OR NOT grade>100;

SELECT * 
FROM customer 
WHERE NOT (city = 'New York' OR grade>100);

SELECT * 
FROM  orders 
WHERE NOT ((ord_date ='2012-09-10' 
AND salesman_id>5005) 
OR purch_amt>1000.00);

SELECT salesman_id,name,city,commission 
FROM salesman 
WHERE (commission > 0.10 
AND commission< 0.12);

SELECT * 
FROM  orders 
WHERE(purch_amt<200 OR 
NOT(ord_date>='2012-02-10' 
AND customer_id<3009));

SELECT * 
 FROM emp_details
  WHERE emp_lname ='Dosni' OR emp_lname= 'Mardy';

SELECT * 
 FROM emp_details
  WHERE emp_dept = 47 OR emp_dept = 63;
  

