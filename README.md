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

## Setup eines virtuellen Python environments

Unter Windows stark empfohlen, unter Linux/macOS optional:
Erstellung eines conda environments.<br/>
Grund: Windows hat per default kein Python, Linux/macOS hat ein Systempython.<br />
(Hinweis: fuer kommerzielle Conda Nutzung Lizenz erforderlich)

```
# Erstellung
$ conda create -n algodaten python=3.9

# Ueberpruefen ob es da ist
$ conda env list

# Aktivieren
$ conda activate algodaten

# Check ob der richtige Interpreter genutzt wird (nur Linux/macOS)
$ which python3
$ which pip3

# Umgebung deaktivieren
$ conda deactivate

# Loeschen der Umgebung
$ conda env remove -n algodaten
```

Mit conda nicht notwendig, unter Linux/macOS bei Nutzung des Systempythons stark empfohlen:
Erstellung einer virtuellen Umgebung.
```
# Erstellung
$ python3 -m venv ~/venv/algodaten

# Aktivierung
$ . ~/venv/algodaten/bin/activate

# Check ob der richtige Interpreter genutzt wird (nur Linux/macOS)
$ which python3
$ which pip3

# Deaktivieren
$ deactivate

# Loeschen
$ rm -r ~/venv/algodaten
```

Fuer die Nutzung des Interpreters in VS Code empfiehlt es sich, `ipykernel` zu installieren.
Dazu zuerst das venv oder conda env aktivieren!

```
# Installation des Pakets "ipykernel"
$ pip3 install ipykernel
# Installation der kernel specification fuer Jupyter in den user space
$ python3 -m ipykernel install --user
Installed kernelspec python3 in /Users/XXX/Library/Jupyter/kernels/python3
```

Installation von numpy via `pip3 install numpy`

In VS Code: Oeffnen der Command Palette via
Cmd+Shift+P (macOS) bzw. Strg+Shift+P (Windows)

Python: Select Interpreter<br />
Dann den "algodaten" Interpreter auswaehlen.

