
# this line has been replaced with int _ instead of string:
#    expectThat("in fact, it's a pointer manipulation II",_______,string(s2+16));

require './replacer'

sourcedirname = "CPPKoans"

puts "WARNING - this will modify the actual source files!"
puts "if you want to continue type 'yes'"
confirmation = gets 
confirmation.strip!
confirmation = "yes"
if ("yes" == confirmation)
  puts "OK...."
  r = Replacer.new
  r.doit File.join(File.dirname(File.realpath(__FILE__)),'..',sourcedirname)
 else 
  puts "not doing anything"
end


