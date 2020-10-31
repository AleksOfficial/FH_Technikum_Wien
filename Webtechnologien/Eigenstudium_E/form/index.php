<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <!-- This is library. pls be quiet in library -->
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/css/bootstrap.min.css"
    integrity="sha384-TX8t27EcRE3e/ihU7zmQxVncDAy5uIKz4rEkgIXeMed4M0jlfIDPvg6uqKI2xXr2" crossorigin="anonymous">
    <style>
      .container{
        width: 800px;
      }
      .lead{
        text-align: center;
      }
      body{
        
        background-color:lightblue;
      }
      
    </style>
  <title>Formular</title>
</head>

<body>
  <div class="container">
    <div class="background-top">
    <h1 class="display-3">Patientenverwaltung</h1>
    <p class="lead">Willkommen im BSA-KIS (BSA Krankenhausinformationssystem!)</p>
  </div>
    <h2>Neuen Patienten Anlegen</h2>
    <form action="./auswertung.php/" method="post">
    <div class="form-group">
        <div class="form-row">
          <div class="col">
            <label for="vorname">Vorname:</label>
          </div>
          <div class="col">
            <input type="text" class="form-control" id="vorname" name="vorname" placeholder="Max" required>
          </div>
          </div>
        </div>
        <div class="form-group">
          <div class="form-row">
          <div class="col">
          <label for="nachname">Nachname: </label>
          </div>
          <div class="col">
          <input type="text" class="form-control" id="nachname" name="nachname" placeholder="Mustermann" required>
        </div>
        </div>
      </div>
        <div class="form-group">
          <div class="form-row">
            <div class="col">
          <label for="email">E-Mail-Adresse:</label>
          </div>
          <div class="col">
            <input type="email" class="form-control" id="email" name="email" placeholder="email@mail.com" >
          </div>
          </div>
      </div>
        <div class="form-group">
          <div class="form-row">
            <div class="col">
          <label for="svn">SVN:</label>
            </div>
          <div class="col">
          <input type="text" class ="form-control" id="svn" name="svn" minlength="4" maxlength="4" pattern="\d*"
            placeholder="Genau 4 stellige Nummer" required>
        </div>
      </div>
      </div>
        <div class="form-group">
          <div class="form-row">
            <div class="col">         
          <label for="geburtsdatum">Geburtstagdatum:</label>
        </div> 
        <div class="col">
          <input type="date" class="form-control" id="geburtsdatum" name="geburtsdatum" required>
        </div>
      </div>
      <div class="form-group">
        <div class="form-row">
          <div class="col">
            <label for="beruf">Beruf:</label>
          </div>
          <div class="col">
    <select class="form-control" id="beruf" name="beruf">
      <option value="Angestellter">Angestellter</option>
      <option value ="Arbeiter">Arbeiter</option>
      <option value ="Schüler">Schüler/Student</option>
      <option value ="Karenz">Karenz</option>
      <option value ="Arbeitslos">Arbeitslos</option>
    </select>
    </div>
    </div>
      </div>
        <!-- Placeholder funktioniert nicht, vl mit JS oder so-->

      <div class="form-group">
        <div class="form-row">
          <div class="col">
        <label for="male">Geschlecht:</label>
        </div>
        <div class="col">
        <input type="radio" id="male" name="geschlecht" value="Männlich">
        <label for="male"> männlich</label>
      </div>
      <div class="col">
        <input type="radio" id="female" name="geschlecht" value="Weiblich">
        <label for="female"> weiblich</label>
      </div>
      <div class="col">
        <input type="radio" id="no_input" name="geschlecht" value="k.A." checked>
      
        <label for="no_input"> keine Angabe</label>
      </div>
      </div>
    </div>
      <div class="form-group">

      <div class="form-row">
        <div class="col">
        <label for="d_blutdruck">Diastolischer Blutdruck:</label>
      </div>
        <div class="col">
        <input type="text" class="form-control" id="d_blutdruck" name="d_blutdruck" pattern="\d*" placeholder="max. drei stellige Nummer"
          maxlength="3" >
        </div>
        </div>
      <div class="form-row">
        <div class="col">
        <label for="s_blutdruck">Systolischer Blutdruck: </label>
        </div>
        <div class="col">
        <input type="text" class="form-control" id="s_blutdruck" name="s_blutdruck" pattern="\d*" placeholder="max. drei stellige Nummer"
          maxlength="3" ></div>
        </div>
      <div class="form-row">
        <div class="col">
        <label for="puls">Puls: </label>
      </div>
        <div class="col">
        <input type="text" class="form-control"id="puls" name="puls" pattern="\d*" placeholder="max. drei stellige Nummer" >
      </div>
    </div>
    </div>
    <div class="form-group">
        <div class="form-row">
        
          <div class="custom-control custom-checkbox">
  <input type="checkbox" class="custom-control-input" id="stationär" name="stationaer" value="auf der Station">
  <input type="hidden" id="stationär" name="stationaer" value="Nicht auf der Station">
  <label class="custom-control-label" for="stationär">Stationäre Aufnahme</label>
      </div>
          </div>
       </div> 
    <div class="form-group">
      <div class="form-row">
        <label for="anmerkungen">Anmerkungen:</label>
      </div>
      <div class="form-row">
        <textarea id="anmerkungen" class="form-control" name="anmerkungen" rows="3" cols="50"
          placeholder="Geben Sie hier ihre zusätzlichen Anmerkungen ein"></textarea>
        </div>
      
      </div>
        <input type="submit" class="btn btn-primary" value="Abschicken">
        <button type="reset" class="btn btn-secondary">Reset</button>
        
    </form>
  </div>

</body>

</html>