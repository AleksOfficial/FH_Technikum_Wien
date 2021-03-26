//functions
function choose_card(id)
{
  if(current_cards.length<2)
  {
    current_cards.push(id);
    show_cards(id);
    if(current_cards.length==2)
    {
      rounds++;
      document.getElementById("rounds").innerHTML=rounds;
      setTimeout(hide_cards,2000);   
    }
  }
}
function show_cards(id)
{
  let value = cards[id-1];
  let url = "url(./pics/card"+value+".png)"
  console.log(url);
  document.getElementById(id).setAttribute("style","background-image: "+url+";");
}
function hide_cards()
{
  if(check_cards())
  {
    let url = "url(./pics/memoryBgI.png)";
    for(let i = 0; i<current_cards.length;i++)
    {
      document.getElementById(current_cards[i]).setAttribute("style","background-image: "+url+";");
      document.getElementById(current_cards[i]).removeAttribute("onclick");
    }
  }
  else{
    for(let i = 0; i<current_cards.length;i++)
    {
      document.getElementById(current_cards[i]).removeAttribute("style");
    }
  }
  current_cards = [];  
}
function check_cards()
{
  let value1= cards[current_cards[0]-1];
  let value2= cards[current_cards[1]-1];
  console.log(value1);
  console.log(value2);
  
  if((17-value1) == value2)
  {
    console.log(true);
    return true;
  }
  else
  {
    console.log(false);
    return false;
  }

}
function shuffle_cards()
{
  
  for(let i =0; i<cards.length;i++)
  {
    let new_index = (Math.floor((Math.random()*100))%cards.length);
    let temp = cards[new_index];
    cards[new_index] = cards[i];
    cards[i]=temp;
  }
}

function increase_time()
{
  timer++;
  document.getElementById("time").innerHTML=timer;
}

//Setup
//Define Timestamps/Names and cards
let player = window.prompt("Please Enter your name","Player 1");
document.getElementById("playername").innerHTML = player;
let cards = []
let main = document.getElementById("spielbereich");
let rowcount = 1;
let container = document.createElement("div");
let current_cards = [];
let timer = 0;
let rounds = 0;
//timer
var x = setInterval(increase_time,1000);


for(var i = 0; i<16;i++)
{
  
  if(!(i%4))
  { 
    container = document.createElement("div");
    container.className="reihe "+rowcount;
    main.appendChild(container);
    rowcount++;
  }
    let div = document.createElement("div");
    div.className="karte";
    div.id=i+1;
    div.setAttribute("onClick","choose_card("+div.id+")");
    container.appendChild(div);
    cards.push(div.id);
}
console.log(cards);
shuffle_cards();
