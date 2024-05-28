set style data boxplot
set style fill solid 0.4 border -1
set style boxplot outliers pointtype 2
set xrange[1:16]
set yrange[0.0:9923700]
plot for[i=1:15] "mkl.txt" using(i):i notitle
set terminal png
set output "mkl_boxplot.eps"
replot
set terminal png