SELECT data FROM imieniny WHERE imiona LIKE '%Karola%';

SELECT imiona FROM imieniny WHERE data = '05-04';

SELECT COUNT(DISTINCT data) AS liczba_dat FROM imieniny WHERE imiona LIKE '%mir%';

ALTER TABLE imieniny ADD COLUMN zyczenia VARCHAR(500);
