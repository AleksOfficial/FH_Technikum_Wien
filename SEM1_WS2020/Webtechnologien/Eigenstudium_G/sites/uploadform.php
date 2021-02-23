<form action ="dropbox.php" method="POST">
<div class="form-row">
  <div class="form-col">

  <input type="input" class="form-control" placeholder="Your Folder Name here" name = "foldername" required>
</div>
<div class="form-col">
  <button type="submit" class="btn btn-primary" name="submit_folder">Create Folder</button>
</div>
  </div>
</form>
<form action ="dropbox.php" method="POST" enctype="multipart/form-data">
<div class="form-row">
  <div class="form-col">

  <input type="file" name = "file">


</div>
<div class="form-col">
  <button type="submit" class="btn btn-primary" name="submit">Upload</button>
</div>
  </div>
</form>

<a class="nav-link" href="dropbox.php?sess=1">Logout</a>