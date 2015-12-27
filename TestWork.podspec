Pod::Spec.new do |s|
  s.name         = "TestWork"
  s.version      = "1.0.0"
  s.summary      = "TestWork SDK"
  s.homepage     = "https://github.com/zlbfzl/TestWork"

  s.license      = { :type => "MIT", :file => "FILE_LICENSE" }
  s.source_files  ="include/*.h"
  s.platform = :ios, '6.0'
  s.author       = { "zl" => "295233275@qq.com" }
  s.source       = { :git => "https://github.com/zlbfzl/TestWork.git", :tag => "#{s.version}" }
  s.resources = "TestWork.bundle"
  s.ios.vendored_frameworks = 'TestWork.framework'
  s.ios.vendored_libraries = 'libSobotLib.a'
  s.frameworks = 'UIKit','Foundation'
end
