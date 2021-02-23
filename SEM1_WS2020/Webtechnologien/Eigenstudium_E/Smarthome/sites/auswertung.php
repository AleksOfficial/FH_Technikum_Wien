<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <!-- This is library. pls be quiet in library -->
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/css/bootstrap.min.css">

  <title>Document</title>
</head>

<body>
  <?php
  $Datanames = array(
    "Anrede","Name","E-Mail","Message"
  );

  $var = 0;

  echo "<table class=\"table\">\n";
  echo "<thead>\n";
  echo "<tr>";
  echo "<th scope=\"row\">#</th>";
  echo "<th scope=\"row\">Datenart</th>";
  echo "<th scope=\"row\">Daten</th>";
  echo "</tr>";
  echo "<tbody>";
  foreach ($_POST as $x => $value) {
    if ($value != "") {
      echo "<tr>\n";
      echo "<th scope=\"row\">" . ($var + 1) . "</th>\n";
      echo "<td>" . $Datanames[$var] . "</td>\n";
      echo "<td>$value</td>\n";
      $var++;
    } else {
      echo "<tr class=\"table-danger\">\n";
      echo "<th scope=\"row\">" . ($var + 1) . "</th>\n";
      echo "<td>" . $Datanames[$var] . "</td>\n";
      echo "<td>MISSING_DATA</td>\n";
      echo "</tr>\n";
      $var++;
    }
  }
  echo "</tbody>\n";
  echo "</table>\n";
  echo "<form action=\"../../index.php\">\n";
  echo "<input type = submit class=\"btn btn-primary\" value=\"Return to home\">\n</form>";
  ?>

</body>

</html>