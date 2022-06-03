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

/*
Query the list of CITY names that do not begin with a vowel
or end with a vowel. Result cannot contain duplicates.
*/
select distinct city
from station
where city not rlike '^[aeiou]'
or city not rlike '[aeiou]$';

/*
Query the list of CITY names that do not begin with a vowel
and does not end with a vowel. Your result cannot contain duplicates.
*/
select distinct city
from station
where city not rlike '^[aeiou]'
and city not rlike '[aeiou]$';

/*
Query the sum of Northern Latitudes (LAT_N) from STATION having values greater than 38.7880 and less than 137.2345. 
Truncate your answer to 4 decimal places.
*/
select round(sum(lat_n), 4)
from station
where lat_n > 38.7880 and lat_n < 137.2345;

/*
Query the greatest value of the Northern Latitudes (LAT_N) from STATION that is less than 137.2345. 
Truncate your answer to 4 decimal places.
*/
select round(max(lat_n), 4)
from station
where lat_n < 137.2345;

