
Pod::Spec.new do |spec|

  spec.name         = "YF_Guild_Temp"
  spec.version      = "1.0.0"
  spec.summary      = "邮件系统"

  spec.description  = <<-DESC
  iOS邮件系统功能库
                   DESC

  spec.homepage     = "https://github.com/leonard-li/YF_EmailKit_Temp.git"


  spec.license      = { :type => "MIT", :file => "LICENSE" }

  spec.author             = { "leonard.li" => "495145872@qq.com" }

  spec.ios.deployment_target = "9.0"

  spec.source       = { :git => "https://github.com/leonard-li/YF_EmailKit_Temp.git", :tag => spec.version }

  spec.vendored_frameworks = 'YFEmailKit.framework'

  spec.requires_arc = true

  spec.dependency "YF_Core"

  spec.resource_bundles = {
    'YF_EmailResources' => ['Resources/PrivacyInfo.xcprivacy']
  }

end
