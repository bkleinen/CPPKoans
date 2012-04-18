require './replacer'

puts "WARNING - this will modify the actual source files!"
puts "if you want to continue type 'yes'"
confirmation = gets 
confirmation.strip!
confirmation = "yes"
if ("yes" == confirmation)
  puts "OK...."
  r = Replacer.new
  r.doit File.join(File.dirname(File.realpath(__FILE__)),'..','src')
 else 
  puts "not doing anything"
end


