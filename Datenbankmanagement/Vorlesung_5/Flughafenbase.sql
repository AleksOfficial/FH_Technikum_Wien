SELECT p.vorname, p.nachname
  FROM person p
JOIN reisepass r
  ON p.personID = r.personID
JOIN land l
  ON l.landID = r.landID
  WHERE l.landID = 43;


SELECT p1.vorname, p1.nachname, g.monatsgehalt
  FROM person p1
JOIN personal p2
  ON p1.personID = p2.personID
JOIN gehaltsstufe g
  ON g.gehaltsstufeID=p2.gehaltsstufeID;

SELECT p1.vorname, p1.nachname, g.monatsgehalt
  FROM person p1
JOIN personal p2
  ON p1.personID = p2.personID
JOIN gehaltsstufe g
  ON g.gehaltsstufeID=p2.gehaltsstufeID
  WHERE g.monatsgehalt > (SELECT AVG(monatsgehalt)
  FROM gehaltsstufe g1 JOIN personal p3 ON g1.gehaltsstufeID = p3.gehaltsstufeID);

