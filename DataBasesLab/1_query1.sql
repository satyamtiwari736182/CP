SELECT * FROM salesman;

SELECT "This is SQL Exercise, Practice and Solution";

SELECT 5, 10, 15;

SELECT 10 + 15;

SELECT 10 + 15 - 5 * 2;

SELECT name, commission
	FROM salesman; 
    
SELECT DISTINCT salesman_id
FROM orders;

SELECT name,city
FROM salesman
WHERE city='Paris';

SELECT *FROM customer
WHERE grade=200;

SELECT ord_no, ord_date, purch_amt
FROM orders
WHERE salesman_id=5001;

SELECT year,subject,winner 
FROM nobel_win 
WHERE year=1970;

SELECT year, subject
FROM nobel_win
WHERE winner = 'Dennis Gabor';

SELECT winner
FROM nobel_win
WHERE year = 1971
AND subject = 'Literature';

SELECT winner 
FROM nobel_win
WHERE year>=1950
AND subject='Physics';

SELECT year, subject, winner, country
  FROM nobel_win
 WHERE subject = 'Chemistry'
   AND year>=1965 AND year<=1975;
   
   SELECT * FROM nobel_win
 WHERE year >1972
  AND winner IN ('Menachem Begin',
                  'Yitzhak Rabin');

SELECT *
 FROM nobel_win 
   WHERE winner LIKE 'Louis %';

SELECT * FROM nobel_win WHERE subject ='Physics' AND year=1970
 UNION 
SELECT * FROM nobel_win  WHERE subject ='Economics' AND year=1971;

SELECT *
 FROM nobel_win 
   WHERE year=1970
    AND subject NOT IN('Physiology','Economics');

SELECT * FROM nobel_win WHERE subject ='Physiology' AND year<1971
 UNION
SELECT * FROM nobel_win WHERE subject ='Peace' AND year>=1974;

SELECT *
 FROM nobel_win 
   WHERE winner='Johannes Georg Bednorz';

SELECT * 
 FROM nobel_win 
  WHERE subject NOT LIKE 'P%' 
   ORDER BY year DESC, winner;

SELECT * FROM item_mast
   WHERE pro_price BETWEEN 200 AND 600;

SELECT AVG(pro_price) FROM item_mast 
  WHERE pro_com=16;

 SELECT pro_name as "Item Name", pro_price AS "Price in Rs."
    FROM item_mast;

SELECT pro_name, pro_price 
     FROM item_mast
    WHERE pro_price >= 250
 ORDER BY pro_price DESC, pro_name;

SELECT AVG(pro_price), pro_com
    FROM item_mast
GROUP BY pro_com;

SELECT DISTINCT emp_lname
FROM emp_details;

SELECT * 
 FROM emp_details 
  WHERE emp_lname= 'Snares';


SELECT * 
 FROM emp_details 
  WHERE emp_dept= 57;





