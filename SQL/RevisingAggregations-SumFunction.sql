/*
Query the total population of all cities in CITY where District is 'California'.
*/
Select sum(population)
from city
where district like "California";
