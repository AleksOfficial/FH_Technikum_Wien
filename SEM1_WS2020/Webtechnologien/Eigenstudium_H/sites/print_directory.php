<?php

    echo "<table class=\"table\">\n";
    echo "<thead>\n";
    echo "<tr>\n";
    echo "<th scope=\"row\">#</th>\n";
    echo "<th scope=\"row\">Filename</th>\n";
    echo "<th scope=\"row\">Filetype</th>\n";
    echo "<th scope=\"row\">Delete</th>\n";
    echo "</tr>";
    echo "<tbody>";
    $folder_array = $_SESSION['filesystem']->getAllFolders();
    $var = 1;
    foreach ($folder_array as $value) {
          echo "<tr class=\"table-warning\">\n";
          echo "<th scope=\"row\">" . $var . "</th>\n";
          echo "<td><a href=\"dropbox.php?cd=$value\">$value</a></td>\n";
          echo "<td><a href=\"dropbox.php?cd=$value\">Directory</td>\n";
          echo "<td>";
          if($value!="..")
            echo "<a href=\"dropbox.php?del=$value\">X</a>";
          echo "</td>";
          echo "</tr>\n";
          $var++;
        }

    $file_array = $_SESSION['filesystem']->getAllFiles();
    foreach($file_array as $value)
    {
      echo "<tr>\n";
      echo "<th scope=\"row\">" . $var . "</th>\n";
      echo "<td>" . $value->filename . "</td>\n";
      echo "<td>$value->datatype - file</td>";
      echo "<td><a href=\"dropbox.php?del=$value->filename\">X</a></td>";
      echo "</tr>\n";
      $var++;
    }
  
    echo "</tbody>\n";
    echo "</table>\n";
  
  
?>