
use testdb;


-- 	*********************************************************************
-- 				creating function

delimiter //
CREATE FUNCTION sample_world(item numeric(6))
returns varchar(18)
    DETERMINISTIC
BEGIN
	declare myItem char(30);
    if item <1000 then
		set myItem="small ticket Item";
	elseif (item>1000 and item<10000) then
		set myItem="Medium Ticket item";
	elseif (item > 10000) then
		set myItem="Big Ticket item";
	else
		set myItem="For Sale";
	end if;

RETURN myItem;
END //

-- 
--                Applying function on the table

select name, state,baldue,sample_world(baldue)
from
	client_master_1157
order by 
	baldue asc;

-- 
drop function sample_fun;
-- **************************************************************************

delimiter //
create function sample78()
returns integer
deterministic

BEGIN

return 123;

END //








