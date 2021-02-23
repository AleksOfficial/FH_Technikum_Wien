<?php
include("./sites/gallery_class.php");
$gallery_pics = array();
foreach (scandir("./pics/") as $value) {
  if ($value == "." || $value == "..")
    continue;
  $file_infos = pathinfo("./pics/" . $value);
  $file_on_drive = new Singlefile($file_infos, 0);
  if ($file_on_drive->error === 0)
    array_push($gallery_pics, $file_on_drive);
}
if (isset($_POST['submit'])) {

  $file = $_FILES['file'];

  $file_upload = new Singlefile($file, 1);
  if ($file_upload->error === 0)
    array_push($gallery_pics, $file_upload);
}


?>
<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/css/bootstrap.min.css" integrity="sha384-TX8t27EcRE3e/ihU7zmQxVncDAy5uIKz4rEkgIXeMed4M0jlfIDPvg6uqKI2xXr2" crossorigin="anonymous">
  <title>Document</title>
  <style>
    body {
      padding: 5px;
    }
  </style>
  <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js" integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj" crossorigin="anonymous"></script>
  <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.1/dist/umd/popper.min.js" integrity="sha384-9/reFTGAW83EW2RDu2S0VKaIzap3H66lZH81PoYlFhbGU+6BZp6G7niu735Sk7lN" crossorigin="anonymous"></script>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/js/bootstrap.min.js" integrity="sha384-w1Q4orYjBQndcko6MimVbzY0tgp4pWB4lZ7lr30WKz0vr/aWKhXdBNmNb5D92v7s" crossorigin="anonymous"></script>

</head>

<body>

  <h1 class="display-4">Gallery 0.1</h1>
  <div id="carouselExampleCaptions" class="carousel slide" data-ride="carousel">
    <ol class="carousel-indicators">
      <?php
      //Liste mit Aktivbar
      for ($x = 0; $x < count($gallery_pics); $x++) {
        echo '<li data-target="#carouselExampleCaptions" data-slide-to="' . $x . ($x == 0 ? '" class="active"></li>' : '"></li>');
      }
      ?>
    </ol>
    <div class="carousel-inner">
      <?php
      foreach ($gallery_pics as $x => $value) {
        echo '
      <div class="carousel-item' . ($x == 0 ? ' active">' : '">') . '
      <img src="' . $value->full_filepath() . '"class="d-block w-100" alt="Bild' . $x . '">
      <div class="carousel-caption d-none d-md-block">
        <h5>Bild' . $x . '</h5>
      </div>
    </div>';
            }
      ?>
    </div>
    <a class="carousel-control-prev" href="#carouselExampleCaptions" role="button" data-slide="prev">
      <span class="carousel-control-prev-icon" aria-hidden="true"></span>
      <span class="sr-only">Previous</span>
    </a>
    <a class="carousel-control-next" href="#carouselExampleCaptions" role="button" data-slide="next">
      <span class="carousel-control-next-icon" aria-hidden="true"></span>
      <span class="sr-only">Next</span>
    </a>
  </div>
  <form action="gallery.php" method="POST" enctype="multipart/form-data">
    <div class="form-row">
      <h3>Formular zum Dateiupload</h3>
    </div>
    <div class="form row">
      <div class="form-col">
        <input type="file" name="file">

        <button type="submit" class="btn btn-primary" name="submit">Upload</button>
      </div>

      <div class="col-7">
        <?php
        
        foreach ( $gallery_pics as $x => $value) {
          echo '<img class="img-thumbnail" src="'.$value->full_filepath().'" alt="Card image cap" style="max-width: 33%; height:auto">';
        }

        ?>
      </div>
    </div>
  </form>



</body>

</html>