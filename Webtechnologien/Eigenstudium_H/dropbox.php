<?php
include "./sites/launch.php";


?>
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/css/bootstrap.min.css"
    integrity="sha384-TX8t27EcRE3e/ihU7zmQxVncDAy5uIKz4rEkgIXeMed4M0jlfIDPvg6uqKI2xXr2" crossorigin="anonymous">
  <title>Document</title>
  <style>
      .container{
        width: 800px;
      }
    </style>
</head>
<body>
  <div class="container">
  <h1 class="display-4">Dropbox 0.1</h1>
  <?php
    
    if($_SESSION['logged'])
    {
      
      include "./sites/CRUD.php";
      include "./sites/upload.php";
      include "./sites/print_directory.php";
      include "./sites/uploadform.php";
      
    }
    else
    {
      include "./sites/login.php";
    }
    

  ?>
  </div>
</body>
</html>