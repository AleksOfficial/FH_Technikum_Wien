<?php 




  if($_SESSION['username']!=""&& !$_SESSION['logged'])
  {
    echo '<div class="alert alert-danger" role="alert"><p>Ur not a doctor... </p></div>';
    
  }


 
//wenn $_SESSION['username'] = correct ^ pw correct; -> logged = TRUE 
if($_SESSION['logged'])
{ if(isset($_SESSION['eingabe']))
  {

  
//Session array daten
  unset($_SESSION['eingabe']['confirmation']);
  $Datanames = array(
    "vorname"=>"Vorname", "nachname"=>"Nachname","email"=> "E-Mail-Adresse","svn"=> "SVN", "geburtsdatum"=>"Geburtsdatum", "beruf"=>"Beruf",
    "geschlecht"=> "Geschlecht", "d_blutdruck"=> "Diastolischer Blutdruck", "s_blutdruck"=>"Systolischer Blutdruck", "puls"=> "Puls", "stationaer"=>"Stationäre Aufnahme",
    "anmerkungen"=> "Anmerkungen"
  );
  $var = 0;
  if(isset($_SESSION['eingabe']['geburtsdatum']))
  {
    $geb_date = explode("-", $_SESSION['eingabe']['geburtsdatum']);
    $SVN = $_SESSION['eingabe']['svn'] . " " . $geb_date[2] . $geb_date[1] . str_split($geb_date[0], 2)[1];
  }
  else
  {
    if(isset($_SESSION['eingabe']['svn']))
    $SVN = $_SESSION['eingabe']['svn'];
  }

  
  echo "<table class=\"table\">\n";
  echo "<thead>\n";
  echo "<tr>\n";
  echo "<th scope=\"row\">#</th>\n";
  echo "<th scope=\"row\">Datenart</th>\n";
  echo "<th scope=\"row\">Daten</th>\n";
  echo "<th scope=\"row\">Delete</th>\n";
  echo "</tr>";
  echo "<tbody>";
  foreach ($_SESSION['eingabe'] as $x => $value) {
    if ($value != "") {
      echo "<tr>\n";
      echo "<th scope=\"row\">" . ($var + 1) . "</th>\n";
      echo "<td>" . $Datanames[$x] . "</td>\n";
      if ($x != "svn") {
        echo "<td>$value</td>\n";
      } else
        echo "<td>$SVN</td>\n";
        echo "<td><a href=\"index.php?del=".$x."&tab=3\">X</a></td>";
      echo "</tr>\n";
      $var++;
    } else {
      echo "<tr class=\"table-danger\">\n";
      echo "<th scope=\"row\">" . ($var + 1) . "</th>\n";
      echo "<td>" . $Datanames[$x] . "</td>\n";
      echo "<td>MISSING_DATA</td>\n";
      echo "<td><a href=\"index.php?del=".$x."&tab=3\">X</a></td>";
      echo "</tr>\n";
      $var++;
    }
  }
  echo "</tbody>\n";
  echo "</table>\n";
}
else
{
  echo '<div class="alert alert-danger" role="alert"><p>Oof! Ich hab keine Daten gefunden... </p></div>';
  echo '<div class ="text-center"><img src="./src/img/neuer_patient_2.jpg"></div>';
}
}
else{
  echo '
<form class="w-75" action="index.php?tab=3" method="POST">
<div class="mb-3">
    <label for="username" class="form-label">Username</label>
    <input type="text" name="username" class="form-control" id="username" placeholder="username"
        required>
</div>
<div class="mb-3">
    <label for="password" class="form-label">Password</label>
    <input type="password" class="form-control" id="password" name="password" placeholder="password"
        required>
</div>
<div class="row">
    <div class="col-md-6">
        <div class="form-check">
            <input class="form-check-input" type="checkbox" value="true" id="keep_logged_in" name="keep_logged_in">
            <label class="form-check-label" for="keep_logged_in">
                Keep me logged in
            </label>
        </div>
    </div>
</div>
<button type="submit" class="btn-secondary btn btn-custom btn-lg btn-block mt-3 ">Login Now</button>
</form>
';
if($_SESSION['username']=="")
echo '<div class ="text-center"><img src="./src/img/neuer_patient.jpg"></div>';
}

  if($_SESSION['username'] ==$username && $_SESSION['password'] ==$password)
  {
    $_SESSION['logged'] = true;
  }
  else if($_SESSION['username']!="")
  {
   
    echo '<div class ="text-center"><img src="./src/img/neuer_patient_2.jpg"></div>';
  }

  ?>