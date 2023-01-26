# minitalk
Ce projet a pour but de vous faire réaliser un petit programme d’échange de données
utilisant les signaux UNIX.
un programme de communication sous la forme d’un client et
d’un serveur:

• Le serveur doit être lancé en premier et doit, après le lancement, afficher son PID.

• Le client prend deux paramètres :

     ◦ Le PID du serveur.
  
     ◦ Une chaîne de caractères à transmettre.
  
• Le client doit communiquer au serveur la chaîne passée en paramètre.
Une fois la chaîne entièrement reçue, le serveur doit l’afficher.

• Le serveur doit être capable d’afficher la chaîne rapidement. Par rapidement, on
entend que si vous pensez que c’est trop long, alors c’est sûrement trop long.

==> serveur doit pouvoir recevoir des chaînes de plusieurs clients à la suite sans
nécessiter d’être relancé.


Liste des bonus :
• Le serveur confirme la réception de chaque message en envoyant un signal au client.

• Le support des caractères Unicode !
