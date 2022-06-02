/*
Query the total population of all cities in CITY where District is 'California'.
*/
Select sum(population)
from city
where district like "California";

/*
Query the average population of all cities in CITY where District is 'California'.
*/
select avg(population)
from city
where district like "california";

/*
Query the average population of all cities rounded down to the nearest integer.
*/
select floor(avg(population))
from city;

/*
Query the sum of the population of all Japanese cities in CITY. The countrycode
is 'JPN'
*/
select sum(population)
from city
where countrycode like 'JPN';

/*
Query the difference between the maximum and minimum populations in CITY.
*/
select max(population) - min(population)
from city;
