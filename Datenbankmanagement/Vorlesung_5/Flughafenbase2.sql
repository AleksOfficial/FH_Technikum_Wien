WITH Fluggäste AS {SELECT vorname, nachname
  FROM person
--JOIN personal 
--  ON person.personID = personal.personID
JOIN flugpersonal
  ON personal.personID = flugpersonal.personID
JOIN passagierliste
  ON passagierliste.personID = flugpersonal.personID
}

SELECT vorname, nachname
  FROM person
  