plot "dev_mkl.txt" with yerrorbar
set terminal png
set output "dev_open.png"
replot
set terminal png