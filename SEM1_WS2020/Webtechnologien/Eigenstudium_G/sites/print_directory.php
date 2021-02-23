<?php
    $var = 1;
    $files=scandir($path);
    echo "<table class=\"table\">\n";
    echo "<thead>\n";
    echo "<tr>\n";
    echo "<th scope=\"row\">#</th>\n";
    echo "<th scope=\"row\">Filename</th>\n";
    echo "<th scope=\"row\">Filetype</th>\n";
    echo "<th scope=\"row\">Delete</th>\n";
    echo "</tr>";
    echo "<tbody>";
    foreach ($files as $value) {

      
       if ($value != ".") {
        
        if(is_dir($path."\\".$value))
        {
          
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
          
        else{
          $_=explode(".",$value);
          $file_extension=end($_);
        echo "<tr>\n";
        echo "<th scope=\"row\">" . $var . "</th>\n";
        echo "<td>" . $value . "</td>\n";
        echo "<td>$file_extension-file</td>";
        echo "<td><a href=\"dropbox.php?del=$value\">X</a></td>";
        echo "</tr>\n";
        $var++;}

    }
  }
    echo "</tbody>\n";
    echo "</table>\n";
  
  
?>