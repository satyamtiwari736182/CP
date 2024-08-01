select *from account;
-- insert into account VALUES(1,"sam","$558");
-- insert into account VALUES(2,"ram","$4558");
-- insert into account VALUES(3,"Jam","$5658");

-- select (REGEXP(amount,"[0-9]+")) from account;

-- select id,accountHolder,amount, (cast(replace(amount,'$','') as int)*5*1/100) as interest from account;

insert into account(name,amount) VALUES("Jam","red,yellow,green");
insert into account(name,amount) VALUES("Jam","yellow,green,blue");


SELECT SUBSTRING_INDEX(SUBSTRING_INDEX(amount, ',', 1), ',', -1) as colorfirst,
SUBSTRING_INDEX(SUBSTRING_INDEX(amount, ',', 2), ',', -1) as colorsecond
from account;
