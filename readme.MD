# oep_bead3

A tundra élővilágát zsákmányállat-kolóniák és ragadozókolóniák alkotják, amelyek egyedszámai hatással vannak a többire. Ha a zsákmányállatok száma nagyon nagy, nagyrészük elvándorol, mert nem talál élelmet. Ha a ragadozók száma nagy, gyorsabban fogy a zsákmányállatok száma, mert vadásznak rájuk.

Három ragadozófajt különböztetünk most meg: hóbaglyot, sarki rókát és farkast. Háromfajta zsákmányállat van: lemming, sarki nyúl és ürge. Az egyes kolóniáknak van beceneve, faja, illetve egyedszáma. A következőkben megadjuk, hogy a zsákmányállat-kolóniák miként reagálnak a rájuk vadászó ragadozókolóniákra:

 - Lemming: ha vadásznak rájuk, az egyedszámuk a rájuk vadászó kolónia számának 4-szeresével csökken. Minden második körben megduplázódik az egyedszámuk. 200 fölötti egyedszámnál csökken a számuk 30-ra.

 - Nyúl: ha vadásznak rájuk, az egyed számuk a rájuk vadászó kolónia számának 2-szeresével csökken. Minden második körben másfélszeresére nő az egyedszámuk. 100 fölötti egyedszámnál csökken a számuk 20-ra.

 - Ürge: ha vadásznak rájuk, az egyed számuk a rájuk vadászó kolónia számának 2-szeresével csökken. Minden negyedik körben megduplázódik az egyedszámuk. 200 fölötti egyedszámnál csökken a számuk 40-re.

A ragadozó kolóniák minden körben véletlenszerűen kiválasztanak egy zsákmány kolóniát, amit megtámadnak. Ha nincs elegendő állat a megtámadott kolóniában (azaz nincs annyi egyed, amennyivel fogy a zsákmányok száma, ha megtámadják őket), akkor fogy a ragadozók száma is: közül minden negyedik elpusztul. Minden nyolcadik körben a hóbaglyok 4 egyedenként 1, a rókák 4 egyedenként 3, a farkasok 4 egyedenként 2 utódot fialnak.

Addig szimuláljuk a folyamatot, amíg minden zsákmány kolónia ki nem hal, vagy a zsákmányállatok összesített száma meg nem négyszereződik a kiinduló értékhez képest. Körönként mutassuk meg a kolóniák összes tulajdonságát!

A program egy szövegfájlból olvassa be a kolóniák adatait! Az első sorban a zsákmánykolóniák és a ragadozó kolóniák darabszámai szerepelnek szóközzel elválasztva.

A következő sorok tartalmazzák a kolóniák adatait szóközökkel elválasztva: a becenevüket (szóközök nélküli sztring), a fajukat (amit egy karakter azonosít: h - hóbagoly, s – sarki róka, f – farkas, l – lemming, n – nyúl, u - ürge), és a kezdeti egyedszámukat.

A program kérje be a fájl nevét, majd jelenítse is meg a tartalmát. (Feltehetjük, hogy a fájl formátuma helyes.) <b>Egy lehetséges bemenet</b>:

`4 2`  
`kicsik l 86`  
`picik l 90`  
`szaporak n 26`  
`szorgosak u 12`  
`ehesek f 12`  
`tollasak h 6`  