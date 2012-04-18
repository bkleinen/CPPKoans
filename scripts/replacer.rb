
class Replacer
  @@typehash = {
      'char' => "____",
      'int' => "_____",
      'double' => "______",
      'string' => "_______"}
      
   @@regex = /^(\s*expectThat\("[^"]*",\s*)([^,]*)(,.*\);\s*)$/
   @@c_style_cast = /^\s*(\w+\()(.*)(\))\s*$/
  def dosomething
    "hallo"
  end
  def doit(dirname)
    puts "DOING"
    puts dirname
    Dir.chdir(dirname)
    aboutfiles = Dir.glob("About*.cpp")
    puts aboutfiles
    tmpdir = "temp"
    Dir.mkdir(tmpdir) unless Dir.exist?(tmpdir)
    aboutfiles.each do | file |
      newfilename = File.join(tmpdir,file)
      File.open(newfilename,'w') do | f2 |
        File.open(file,'r') do | f |
          f.each_line do | content |
            newcontent = replace_line(content)
            f2.puts(newcontent)
          end
        end
      end
      File.delete(file)
      File.rename(newfilename,file)
    end
  end
  def replace_line(line)
    m = @@regex.match(line)
    unless m
      return line
    else 
       puts line
       return "" + m[1] + replace_expected(m[2])+m[3]
    end
  end
  def replace_expected(expected_value)
    cast = ""
    tail = ""
    
    m = /(\(.*\))?.*/.match(expected_value)
    if m[1]
      cast = m[1]
    else
      m = @@c_style_cast.match(expected_value)
      if m
        cast = m[1]
        expected_value = m[2]
        tail = m[3]
      end
    end
  
    case expected_value
    when /true/
      return cast + "________" + tail
    when /false/
      return cast + "_________" + tail
    when /_+/
      return expected_value
    when /\d+\.\d+/
      return cast + @@typehash['double'] + tail
    when /\d+/
      return cast + @@typehash['int'] + tail
    when /".*"/
      return cast + @@typehash['string'] + tail
    when /'\w'/
      return cast + @@typehash['char'] + tail
    default
      return cast + expected_value + tail 
    end
    
  end
end


# the definition from Assert.h
#define  'x'
#define   42
#define   42.42
#define   "42"
        

