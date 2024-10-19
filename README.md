# AlgoData
Zur Vorlesung Algorithmen und Datenstrukturen

## ssh

Im `ssh` Ordner befindet sich der private Schluessel fuer den Zugriff auf den Raspberry Pi.

Hinweis: Der private Schluessel wurde absichtlich in zu diesem oeffentlichen Repository hinzugefuegt,
da er nur in Zusammenhang mit dem (lokalen) Netzwerk des Raspberry Pi und
fuer einen non-sudo user genutzt werden kann.

## Nutzung von CMake ueber das Terminal

Zu `.zshrc` folgendes hinzufuegen

```
PATH="/Applications/CMake.app/Contents/bin":"$PATH"
```