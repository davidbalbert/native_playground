#!/usr/bin/env ruby -Ilib

require 'native_playground'

puts 'allocating objects'
50_000_000.times do
  NP::MyStruct.new
end
puts 'done allocating!'
sleep 10
puts 'bye bye!'
