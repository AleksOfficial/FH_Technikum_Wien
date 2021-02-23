<!doctype html>
<html lang="en">

<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="https://fonts.googleapis.com/css2?family=Press+Start+2P&display=swap" rel="stylesheet">
    <link href="https://fonts.googleapis.com/css2?family=Orbitron:wght@400;500;600;700;800;900&display=swap"
        rel="stylesheet">
    <link href="https://fonts.googleapis.com/css2?family=Montserrat:wght@600&display=swap" rel="stylesheet">
    <link href="https://fonts.googleapis.com/css2?family=Open+Sans&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="responsive_uebung1_css.css" type="text/css">
    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css"
        integrity="sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z" crossorigin="anonymous">

    <title>Hello, world!</title>
</head>

<body>
    <nav class="navbar navbar-expand-lg navbar-light bg-light fixed-top">
        <a class="navbar-brand" href="#">Menü</a>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav"
            aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarNav">
            <ul class="navbar-nav ml-auto">

                <li class="nav-item active">
                    <a class="nav-link" href="index.php?menu=info">Home <span class="sr-only">(current)</span></a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="index.php?menu=schlafzimmer">Schlafzimmer</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="index.php?menu=wohnzimmer">Wohnzimmer</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="index.php?menu=esszimmer">Esszimmer</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="index.php?menu=küche">Küche</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="index.php?menu=außenbereich">Außenbereich</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="index.php?menu=kontaktformular">kontaktformular</a>
                </li>


            </ul>
        </div>
    </nav>
    <header>
        <div class="container">
            <h1>Smart Home Controller App v.1.0</h1>
            <p>BSA, 2. Semester</p>
            <p>Demo-App</p>
    </header>

    <main>
    
        <?php 


        if (isset($_GET['menu']))
        {
            $homebutton = TRUE;
            switch ($_GET['menu']) {
                case 'info':
                    include 'sites/info.php';
                    break;
                case 'schlafzimmer':
                    include 'sites/schlafzimmer.php';
                        break;
                case 'wohnzimmer':
                    include 'sites/wohnzimmer.php';
                    break;
                case 'esszimmer':
                    include 'sites/esszimmer.php';
                    break;
                case 'küche':
                    include 'sites/küche.php';
                    break;
                case 'außenbereich':
                    include 'sites/Außenbereich.php';
                    break;
                case 'kontaktformular':
                    include 'sites/kontaktformular.php';
                    break;
                default:
                    include 'sites/404.php';
                    $homebutton =False;
                    break;
            if ($homebutton){}
            echo "<div id=\"return_home\">\n
            <a href=\"index.php\"><img src=\"./img/zuhause.png\" width=\"76\" height=\"76\" alt=\"Return to Home\"></a>\n
        </div>";
            }
        }
        
        ?>
    </main>
    <footer>

    </footer>
    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js"
        integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj"
        crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.1/dist/umd/popper.min.js"
        integrity="sha384-9/reFTGAW83EW2RDu2S0VKaIzap3H66lZH81PoYlFhbGU+6BZp6G7niu735Sk7lN"
        crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"
        integrity="sha384-B4gt1jrGC7Jh4AgTPSdUtOBvfO8shuf57BaghqFfPlYxofvL8/KUEfYiJOMMV+rV"
        crossorigin="anonymous"></script>
    </div>
</body>

</html>