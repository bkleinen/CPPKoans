# this is a simple script that checks if all About* classes are called
# from the main method, and that all about* methods in these files
# are called from the meditate method.

sourcedirname = "CPPKoans"

dirname =  File.dirname(File.realpath(__FILE__))
puts dirname
Dir.chdir(File.join(dirname,"..",sourcedirname))
aboutfiles = Dir.glob("About*.cpp") 
aboutnames = aboutfiles.map{ |f| f.gsub(/.cpp/,"")}

file = File.open("CPPKoans.cpp", "rb")
main = file.read
file.close

aboutnames.each do | about |
  unless main.include? about+"::meditate" 
    puts "!!! Warning: " +about + " is missing in main!!!"
  end 
end

aboutfiles.each do | filename |
  f = File.open(filename,'rb')
  content = f.read
  f.close
  aboutmethods = content.scan /void about.*\(\)/
  aboutmethods = aboutmethods.map{|m| m.gsub(/ *void *(\w*).*/,"\\1")}  
  aboutmethods.each do | aboutmethod |
    
    unless content.match "\s*#{aboutmethod}\\(\\);\s*"
      puts "!!! Missing call to " + aboutmethod +" in "+filename +" !!!"
    end 
  end
end
