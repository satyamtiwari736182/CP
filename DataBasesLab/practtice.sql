show databases;
use plsql;
show tables;
create table Customer(
cust_id int primary key,
name varchar(100),
total_purchase int
);

describe Customer;

create table Category(
Cust_id int,
Name varchar(100),
class varchar(100),
foreign key(Cust_id) references Customer(Cust_id)
);

describe Category;

insert into Customer values(1,"Swapnil",11000);
insert into Customer values(2,"Ganesh",6000);
insert into Customer values(3,"Sourabh",30000);



call proc_grade(11000,1,"Swapnil");
call proc_grade(6000,2,"Ganesh");
call proc_grade(3000,3,"Sourabh");

select *from Category;
select *from Customer;

DELIMITER //
create procedure proc_grade(purchase int,cust_id int,name varchar(100))
	begin
    #Exception Handling
    
		declare continue handler for not found
        begin
			select 'NOT FOUND';
        end;
        #Condition 1
        if(purchase <= 20000 && purchase >= 10000)
        then
			insert into Category values(cust_id,name,"Platinum");
		end if;
        #condition 2
        if(purchase >= 5000 && purchase < 10000)
        then
			insert into Category values(cust_id,name,"Gold");
		end if;
        #condition 3
        if(purchase >= 2000 && purchase < 5000)
        then
			insert into Category values(cust_id,name,"Silver");
		end if;
    end;
//













-- declare
-- -- it gives the final answer after computation
-- fac number :=1;

-- -- given number n
-- -- taking input from user
-- n number := &1;

-- -- start block
-- begin		

-- -- start while loop	
-- while n > 0 loop

-- -- multiple with n and decrease n's value
-- fac:=n*fac;		
-- n:=n-1;		
-- end loop;		
-- -- end loop

-- -- print result of fac
-- dbms_output.put_line(fac);

-- -- end the begin block
-- end;			



















