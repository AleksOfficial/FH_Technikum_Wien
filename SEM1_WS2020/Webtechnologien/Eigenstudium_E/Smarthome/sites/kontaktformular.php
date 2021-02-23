<style>
  #Kontaktformular{
    
    background-position-x: 600px;
    background-position-y: 0px;
    background-image:linear-gradient(to right,rgba(255,255,255,1),rgba(230,15,130,0.2),rgba(255,255,255,1)),url("img/kontakt.png");
    background-repeat: repeat-y;
    background-size:90%;
    color:black;    
    font-family: "Open Sans",monospace;
    padding:25px;
}
#Kontaktformular .wrap{

  max-width: 768px;
  right:20%;
  margin: 30px auto 0;
  position: relative;
  border: solid 2px rgba(39, 38, 121, 0.37);
  
}
form{
    padding:37.5px;
    margin: 50px 0;
}


#Kontaktformular h2{
    color:black;
    margin-left:7%;
    padding-top:100px;
    background-color: transparent;
    
}
#Kontaktformular hr{
    border-style: dashed;
    border-width: 3px;
}

input[type="text"],select, input[type="email"],textarea{
    box-sizing:border-box;
    background: none;
    border:none;
    border-bottom:solid 2px #001540;
    color: #0017BA;
    font-size: 1em;
    padding:0 0 10px 0;
    width:100%;
    

}
button{
background-color: #001540;
  border: solid 2px #474544;
  color: white;
  cursor: pointer;
  padding:15px;
  font-family:"Open Sans";
  font-size:19px;
  border-radius: 5px;;
}
button:hover{
    background-color: #0017BA;
    color:red;
}
.Anrede{
    
    width:100%;
}
.name,.email{
    margin-top:25px;
}
.message{
    margin-top:100px;
}
.name{
    
    float:left;
    width:45%;
}
.email{
    
    float:right;
    width:38%;
}

textarea{
    
    font-family:"Open Sans";
}

  </style>
<section id="Kontaktformular">
            <h2>Ihre Software funktioniert nicht? kontaktieren Sie uns!</h2>
            
            <div class="wrap">

                <form action="./sites/auswertung.php/" method="POST">
                    <div class="Anrede">
                        <label for="Anrede">Anrede:</label> <select name="Anrede" id="Anrede">
                            <option selected="" hidden="">Wählen Sie Ihre Anrede ... </option>
                            <option value="Herr">Herr</option>
                            <option value="Frau">Frau</option>
                        </select></div>
                    <div class="name"><label for="Name">Name:</label>
                        <input type="text" maxlength="20" name="Name" id="Name" required="" placeholder="Vorname Nachname"></div>
                    <div class="email">
                        <label for="E-Mail">E-Mail:</label>
                        <input type="email" name="E-Mail" id="E-Mail" placeholder="sample@mail.no" maxlength="20" required=""></div>
                        <div class="message">
                    <label>Nachricht: </label>
                    <textarea name="Message" id="Nachricht" placeholder="Beschreiben Sie Ihr Problem ... "></textarea></div><br>
                    <button type=submit>Nachricht senden</button>
                </form>
            </div>

        </section>