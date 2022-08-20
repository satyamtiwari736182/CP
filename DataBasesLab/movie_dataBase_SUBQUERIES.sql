-- select a.act_fname,a.act_lname
-- from actor a,movie m,movie_cast mc
-- where m.movie_title='Annie Hall'

select *from actor where act_id in 
	(select act_id from movie_cast where mov_id in 
		(select mov_id from movie where mov_title='Annie Hall'))
        
        
-- 2. From the fo-- llowing tables, write a SQL query to find the director 
-- of a film that cast a 
-- role in 'Eyes Wide Shut'. Return director first name, last name. 

select *from director where dir_id in
	(select dir_id from movie_direction where mov_id in (
			select mov_id from movie where mov_title='Eyes Wide Shut'));
            
-- 3. From the following table, write a SQL query to find those movies 
-- that have been released in countries other than the United Kingdom.
--  Return movie title, movie year, movie time, and date of release, 
--  releasing country
 
 select * from movie where mov_rel_country <> 'UK'
 
 -- From the following tables, write a SQL query to find for movies 
--  whose reviewer is unknown.
--  Return movie title, year, release date, 
--  director first name, last name, actor first name, last name.
 
SELECT mov_title, mov_year, mov_dt_rel, dir_fname,
							dir_lname, act_fname, act_lname
FROM movie a, movie_direction b, director c, 
						rating d, reviewer e, actor f, movie_cast g
WHERE a.mov_id=b.mov_id
	AND  b.dir_id=c.dir_id 
			AND a.mov_id=d.mov_id 
				AND  d.rev_id=e.rev_id 
					AND  a.mov_id=g.mov_id 
						AND g.act_id=f.act_id 
								AND e.rev_name IS NULL;
	
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 