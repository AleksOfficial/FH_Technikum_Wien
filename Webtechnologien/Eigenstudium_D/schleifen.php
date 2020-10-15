<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <link href="https://fonts.googleapis.com/css2?family=Open+Sans&family=PT+Serif&display=swap" rel="stylesheet"> 
  <title>Schleifen</title>
  <style>
    *{
      font-family:"Open Sans";
    }
    table{
      border-style: solid;
      border-color:grey;
      text-align: center;
      font-size: larger;
    }
    td{
      padding:5px;
    }
    .even{
      background-color: lightskyblue;
    }
  </style>

</head>

<body>
  <?php
    echo "<table>";
    $x = 1;
    for ($i = 0; $i < 3; $i++) {
      print("<tr>");
      for ($j = 0; $j < 5; $j++) {

        if ($x % 2) {
          print("<td class ='uneven'>$x</td>");
        } else {
          print("<td class ='even'>$x</td>");
        }
        $x++;
      }
      print("</tr>");
    }
    echo "</table> <br>";
    
    echo "<table>";
    $x = 1;
    $i=0;
    
    while ($i < 3)
    {
      $j=0;
      print("<tr>");
      while($j < 5)
      {
        if ($x % 2) {
          print("<td class ='uneven'>$x</td>");
        } else {
          print("<td class ='even'>$x</td>");
        }
        $x++;
        $j++;
      }
      print("</tr>");
      $i++;
    }
    echo "</table> <br>";

    echo "<table>";
    $x = 1;
    $i=0;
    
    do
    {
      $j=0;
      print("<tr>");
      do
      {
        if ($x % 2) {
          print("<td class ='uneven'>$x</td>");
        } else {
          print("<td class ='even'>$x</td>");
        }
        $x++;
        $j++;
      } while($j < 5);
      print("</tr>");
      $i++;
    } while ($i < 3);
    echo "</table> <br>";
  
    
  ?>
</body>

</html>