# -*- encoding: utf-8 -*-
$:.push File.expand_path("../lib", __FILE__)
require "native_playground/version"

Gem::Specification.new do |s|
  s.name        = "native_playground"
  s.version     = NativePlayground::VERSION
  s.authors     = ["David Albert"]
  s.email       = ["davidbalbert@gmail.com"]
  s.homepage    = ""
  s.summary     = %q{TODO: Write a gem summary}
  s.description = %q{TODO: Write a gem description}

  s.rubyforge_project = "native_playground"

  s.files         = `git ls-files`.split("\n")
  s.test_files    = `git ls-files -- {test,spec,features}/*`.split("\n")
  s.executables   = `git ls-files -- bin/*`.split("\n").map{ |f| File.basename(f) }
  s.require_paths = ["lib"]
  s.extensions = ["ext/native_gem/extconf.rb"]

  s.add_development_dependency "rake-compiler"
end
