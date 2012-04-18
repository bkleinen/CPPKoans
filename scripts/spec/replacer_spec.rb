require './replacer'

describe "replace" do
  before(:each) do
    @rep = Replacer.new
  end
  it "preserves an explicit cast to string" do
    l = %(expectThat("C++ strings are mutable.", (string)"big Bang theory",s);)
    r = %(expectThat("C++ strings are mutable.", (string)_______,s);)
    @rep.replace_line(l).should == r
  end
  it "preserves an explicit c style cast to string" do
    l = %(expectThat("C++ strings are mutable.", string("big Bang theory"),s);)
    r = %(expectThat("C++ strings are mutable.", string(_______),s);)
    @rep.replace_line(l).should == r
  end
  it "replaces booleans" do
    l = %(expectThat("integers are treated as boolean!", true, actual);)
    r = %(expectThat("integers are treated as boolean!", ________, actual);)
   
    @rep.replace_line(l).should == r
  end

  it "replaces chars" do
    l = %(expectThat("direct method call to a", 'a', a.method0());)
    r = %(expectThat("direct method call to a", ____, a.method0());)
    
    @rep.replace_line(l).should == r
  end

  it "leaves ____ alone" do
    l = %(expectThat("direct method call to a", ____, a.method0());)
    r = %(expectThat("direct method call to a", ____, a.method0());)
    
    @rep.replace_line(l).should == r
  end
  
  it "replaces ints" do
    l = %(expectThat("the length of the string is determined by looking for the null char",10,stringLength);)
    r = %(expectThat("the length of the string is determined by looking for the null char",_____,stringLength);)
    @rep.replace_line(l).should == r
  end
  
  it "replaces ints with typecast" do
    
    l = %(expectThat("double takes 8 byte ",(unsigned int)8,sizeof(flying_time));)
    r = %(expectThat("double takes 8 byte ",(unsigned int)_____,sizeof(flying_time));)
    @rep.replace_line(l).should == r
  end
  
  describe "type replacement" do
    it "-- char" do
      @rep.replace_expected("'a'").should == "____"
    end
    it "-- int" do
      @rep.replace_expected("42").should == "_____"
    end
    it "-- int single digit" do
      @rep.replace_expected("9").should == "_____"
    end
    it "-- int with cast" do
      @rep.replace_expected("(unsigned int)9").should == "(unsigned int)_____"
    end
    it "-- string with cast" do
      @rep.replace_expected("(string)\"hallo\"").should == "(string)_______"
    end
    it "-- string with cast + spaces" do
      @rep.replace_expected("(string)\"hallo du da\"").should == "(string)_______"
    end
    it "-- string with c style cast + spaces" do
      @rep.replace_expected("string(\"hallo du da\")").should == "string(_______)"
    end
    it "-- double" do
      @rep.replace_expected("42.42").should == "______"
    end
    it "-- string" do
      @rep.replace_expected("\"big bang theory\"").should == "_______"
    end
    
     
  end
  
end  
  
