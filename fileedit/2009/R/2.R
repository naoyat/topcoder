png(file="fft300.png")
par(bg="grey95", mar=c(4,4,1,1), mfrow=c(2,1))
wave <- read.table("fft00.dat")
plot(wave$V1, type="l")
dev.off()

