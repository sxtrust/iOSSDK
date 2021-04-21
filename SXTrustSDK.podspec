
Pod::Spec.new do |s|
  s.name                  = 'SXTrustSDK'
  s.version               = '1.0.2-beta'
  s.summary               = '山西信托交易iOSSDK组件'

  s.description           = <<-DESC
  山西信托交易iOSSDK组件. 用于授权方在app内部嵌入使用.
                       DESC

  s.homepage              = 'https://github.com/sxtrust/iOSSDK.git'
  s.license               = { :type => 'MIT', :file => 'LICENSE' }
  s.author                = { 'sxxtappdev' => 'sxxtappdev@yingnagroup.com' }
  s.source                = { :git => 'https://github.com/sxtrust/iOSSDK.git', :tag => s.version.to_s }

  s.ios.deployment_target = '8.0'
  s.requires_arc          = true

  s.frameworks            = "AVFoundation","WebKit","JavaScriptCore"
  s.libraries             = 'xml2'
  s.resources             = 'SXTrustSDK/SXTrustSDKBundle.bundle'
  s.vendored_frameworks   = 'SXTrustSDK/SXTrustSDK.framework'  
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

end
