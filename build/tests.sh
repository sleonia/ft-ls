##incorrect
#
#echo "./ft_ls -9 .. . CMakeFiles"; #incorrect
#./ft_ls -9 .. . CMakeFiles;
#echo "\n";
#
#echo "./ft_ls -9"; #print usage and exit
#./ft_ls -9;
#echo "\n";

#correct

#	no dir

echo "./ft_ls"; #no flag
./ft_ls;
echo "\n";

echo "./ft_ls -1"; #one flag
./ft_ls -1;
echo "\n";

echo "./ft_ls -1 -a -R"; #Some divided flags
./ft_ls -1 -a -R;
echo "\n";

echo "./ft_ls -1aR"; #Some flags together
./ft_ls -1aR;
echo "\n";

echo "./ft_ls -1aR -t -l"; #Some flags together and divided
./ft_ls -1aR -t -l;
echo "\n";