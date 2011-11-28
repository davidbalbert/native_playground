require "bundler/gem_tasks"
require 'rake/extensiontask'

Rake::ExtensionTask.new("native_playground") do |ext|
  ext.lib_dir = "lib/native_playground"
end

desc "load native_playground in a pry or irb session (alias `rake c`)"
task :console do
  if system("which pry")
    repl = "pry"
  else
    repl = "irb"
  end

  sh "#{repl} -Ilib -rubygems -rnative_playground"
end

task :c => :console
