# TesteVivo

#Source Code
O codigo está dividido em 3 classes e 1 cpp de Main.

Ele obedece um fluxo de dados. Começa pelo main.cpp que instancia uma unidade da classe #Window. 
Essa classe é responsável por criar um Dialog de input onde o usuário irá inseri o endereço principal do manifest. Por exemplo, se o endereço do manifest é: http://playready.directtaps.net/smoothstreaming/SSWSS720H264/SuperSpeedway_720.ism/Manifest , o endereço principal é: http://playready.directtaps.net/smoothstreaming/SSWSS720H264/SuperSpeedway_720.ism a partir dai ele vai fazer todo o processamento de consumo e instanciará a classe #xmldown.
Essa, por sua vez é responsável por decodificar todo o XML recebido separando as principais informações. Separa só a parte de Video, separa também todos os chunks e capta as informações do XML necessárias.
Assim ele instancia um objeto da classe #smoothStreaming. Onde irá ser feito o download. 
Ela Cria uma janela janela para passar toda informação. 
Primeiro ele baixa toda a informação em Alta qualidade. E escreve em C:/Users/Public/AltaQualidade.mp4. Em seguida ele baixa em Baixa Qualidade e escreve em C:/Users/Public/BaixaQualidade.mp4.
E exibe na dela toda as informações do download.

