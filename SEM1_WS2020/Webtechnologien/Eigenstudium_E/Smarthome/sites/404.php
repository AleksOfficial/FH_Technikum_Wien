<style>
#myVideo{
  position: fixed;
  top:0;
  min-width: 100%;
  min-height: 100%;
}
button{
  width:200px;
  font-size: 18px;
  cursor: pointer;
  border:none;
  background-color: black;
  color:white;
  border-radius: 5px;

}
button:hover{
  background-color:white;
  color:black;
}
.lost{
  position:fixed;
  top:20%;
  margin-left:10%;
  padding:5%;
  color: white;
  background: rgba(0,0,0,0.5);
  border-radius: 10px;
  
}

</style>
<video autoplay muted loop id="myVideo">
  <source src="img/confused.mp4" type="video/mp4">
</video>

<!-- Optional: some overlay text to describe the video -->
<div class="lost">
  <h1>Error 404</h1>
  <h2>Page not Found</h2>
  <p>Our trained monkey hasn't done this part yet..</p>
  <p>go back with the navigation bar or the button below.</p>
  <a href="index.php"><button>Return Home</button></a>
</div>