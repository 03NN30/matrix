#version 330 core
out vec4 FragColor;

in VS_OUT {
  vec3 FragPos;
  vec3 Normal;
} fs_in;

struct DirLight
{
  vec3 direction;

  vec3 ambient;
  vec3 diffuse;
  vec3 specular;
  float ambientStrength;

  float exists;
};

struct PointLight
{
  vec3 position;

  vec3 ambient;
  vec3 diffuse;
  vec3 specular;
  float ambientStrength;

  float constant;
  float linear;
  float quadratic;

  float exists;
};

struct SpotLight
{
  vec3 position;
  vec3 direction;

  float cutOff;
  float outerCutOff;

  vec3 ambient;
  vec3 diffuse;
  vec3 specular;
  float ambientStrength;

  float constant;
  float linear;
  float quadratic;

  float exists;
};

struct Material
{
  vec3 ambient;
  vec3 diffuse;
  vec3 specular;

  float shininess;
};

uniform vec3 viewPosition;

uniform Material material;

#define NR_DIR_LIGHTS 5
#define NR_POINT_LIGHTS 5
#define NR_SPOT_LIGHTS 5

uniform DirLight dir_lights[NR_DIR_LIGHTS];
uniform PointLight point_lights[NR_POINT_LIGHTS];
uniform SpotLight spot_lights[NR_SPOT_LIGHTS];

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

void main()
{
  vec3 norm = fs_in.Normal;
  vec3 fragPos = fs_in.FragPos;
  vec3 viewDir = normalize(viewPosition - fs_in.FragPos);

  FragColor = vec4(CalcPointLight(point_lights[1], norm, fragPos, viewDir).xyz, 1.0);
}

// calculates the color when using a point light.
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
  //if (light.exists == 0.0)
   // return vec3(0.0, 0.0, 0.0);

  // ambient
  vec3 ambient = light.ambientStrength * light.ambient * material.ambient;

  // diffuse
  vec3 lightDir = normalize(light.position - fragPos);
  float diff = max(dot(lightDir, normal), 0.0);
  vec3 diffuse = light.diffuse * diff * material.diffuse;

  // specular
  vec3 halfwayDir = normalize(lightDir + viewDir);
  float spec = pow(max(dot(normal, halfwayDir), 0.0), material.shininess);
  vec3 specular = light.specular * spec * material.specular;

  // attenuation
  float distance    = length(light.position - fragPos);
  float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
  ambient *= attenuation;
  diffuse *= attenuation;
  specular *= attenuation;

  return (ambient + diffuse + specular);
}