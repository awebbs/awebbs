/*
Query the list of CITY names that start with the vowels: (a, e, i, o, or u) from
station. Your result cannot contain duplicates.
*/

select distinct city
from station
where city like ('a%')
or city like ('e%')
or city like ('i%')
or city like ('o%')
or city like ('u%');

/*
Query the list of CITY names that end with the vowels: (a, e, i, o, or u) from
station. Your result cannot contain duplicates.
*/
select distinct city
from station
where city like ('%a')
or city like ('%e')
or city like ('%i')
or city like ('%o')
or city like ('%u');

/*
Query the list of CITY names that begin and end with the vowels: (a, e, i, o, u) from
station. Your result cannot contain duplicates.
*/
select distinct city
from station
where city rlike '^[aeiouAEIOU].*[aeiouAEIOU]$'

/*
Query the list of CITY names that do not begin with an vowel. 
Your result cannot contain duplicates.
*/
select distinct city
from station
where city Not rlike '^[aeiou]';

