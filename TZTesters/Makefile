TZTester.jar: tangentz/TZTester.class
	jar cvf TZTester.jar tangentz/TZTester.class tangentz/TZTester.java

tangentz/TZTester.class: tangentz/TZTester.java
	cd tangentz ; javac -classpath ../ContestApplet.jar -deprecation TZTester.java ; cd ..

install: TZTester.jar
	cp TZTester.jar ~/topcoder/plugins/

clean:
	rm -f tangentz/TZTester.class TZTester.jar tangentz/*~ 
