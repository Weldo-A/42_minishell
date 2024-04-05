# MINISHELL TESTS LOG

verifier variables d'expansion en argument
ls '\'\<newline\>
echo $'anouk\tanouk\nanouk'
anouk	anouk
anouk
gettext
anouk=
anouk=""
anouk+=$zuzu
echo $"\*" (une seule str, param separes par premier char de IFS variable : "$\*"  is equivalent to "$1c$2c..." & un esp si IFS = unset & pas de sep si IFS est null)
echo {1..80}
echo ${anouk}e
echo ${!v\*}
count=$(wc -l <(sort myfile.txt))
for word in $sentence; do echo "Word: $word"; done
echo $'anuk\n\n\n\n'
echo anouk"anouk"
echo 'anouk'"anouk"
echo "anouk"$a"anou\nyoyo" | cat -e
echo "anouk\"$a\"anou\nyoyo" | cat -e
echo "anouk'$a'anou\nyoyo" | cat -e
