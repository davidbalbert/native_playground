# -*- encoding: utf-8 -*-
$:.push File.expand_path("../lib", __FILE__)
require "native_playground/version"

Gem::Specification.new do |s|
  s.name        = "native_playground"
  s.version     = NativePlayground::VERSION
  s.authors     = ["David Albert"]
  s.email       = ["davidbalbert@gmail.com"]
  s.homepage    = ""
  s.summary     = %q{Just a place for me to play around with the ruby c api}
  s.description = %q{Just a place for me to play around with the ruby c api}

  s.rubyforge_project = "native_playground"

  s.files         = `git ls-files`.split("\n")
  s.test_files    = `git ls-files -- {test,spec,features}/*`.split("\n")
  s.executables   = `git ls-files -- bin/*`.split("\n").map{ |f| File.basename(f) }
  s.require_paths = ["lib"]
  s.extensions = ["ext/native_playground/extconf.rb"]

  s.add_development_dependency "rake-compiler"
end
