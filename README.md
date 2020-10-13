<h1>espBOY</h1>

<h2>Introduzione</h2>

Librerie per la realizzazione di un gameBoy basato su microcontrollori esp. 
Il progetto è in stato di sviluppo.

<h2>Hardware</h2>

<p>Di seguito potete osservare le immagini del primo prototipo(sinistra), e della versione 1.0 che aggiunge possibilità di caricare giochi dalla sd (destra). </p>

<image src="https://github.com/LucaCarrero/espBoy_Lib/blob/master/projectFile/IMG_20200906_102929.jpg" width="300" height="400"/>
<h4>Schema elettrico</h4>
<image src="https://github.com/LucaCarrero/espBoy_Lib/blob/master/projectFile/espboy_schema.png" width="650" height="400"/>
<p>a breve arriverà anche il procetto con misure della pcb, con relativo file per poterla realizzare ed elenco dei componenti.<p/>
<h2>Software</h2>

Il software presente è composto da una serie di librerie che mirano a creare un ambiente di sviluppo di vidiogiochi e aplicazioni sulla piattaforma.
Librerie presenti, create da me, per la gestione dell'hardware sono:
    <li><a href="https://github.com/LucaCarrero/espBoy_Lib/tree/master/lib/Menu">Menu</a>: libreria per realizzare un semplice menu su display grafici compatibili con la libreria u8g2,</li>
    <li><a href="https://github.com/LucaCarrero/espBoy_Lib/tree/master/lib/sdUtility">SdUtility</a>: libreria che mette a disposizione una serie di funzionalità per lavorare con i file presenti nella SD,</li>
    <li><a href="https://github.com/LucaCarrero/espBoy_Lib/tree/master/lib/BootLoader">BootLoader</a>: contiene la funzione che carica lo sketch che permette la selezione dei giochi presenti sulla SD( richiede la libreria SdUtility),</li>
    <li><a href="https://github.com/LucaCarrero/espBoy_Lib/tree/master/lib/KeyController">KeyController</a>: libreria che facilita allo sviluppatore la gestione degli input dei pulsanti(libreria basata su quella dell'extender di pin digitali I/O pcf7584).</li>
    <p>
<p>Librerie per lo sviluppo di giochi da me create:</p>
<li> ><a href="https://github.com/LucaCarrero/espBoy_Lib/tree/master/lib/GameObject">GameObject</a>: Libreria di base su qui basare gli oggetti di gioco. (cordinate e dimensioni del componente e rilevamento delle collisioni fra compinenti)

<h2>Come Sviluppare</h2> 
Installare Visual Studio Code e il plugin PlatformIO.
Clonare o scaricare il progetto e aprirlo con PlatformIO.

<h2>Sviluppi Futuri</h2>
Una volta ultimato il pachetto di librerie mi piacerebbe realizzare un motore grafico 2d per semplificare lo sviluppo, 
 rendere compatibile l'ambiente di sviluppo con tutti i microcontrollori programmabili con l'Arduino core e usare display tft a colori per dare la possibilità di realizzare giochi a colori.
 
<h4>TODO: </h4>Ultimare le librerie per la gestione dell'hardware.<p>Insieme di classi e utility per lo sviluppo di videogiochi.<p>wiki per descrivere il funzionamento delle librerie
