/**
* Inexor Entity System
* No description provided (generated by Openapi Generator https://github.com/openapitools/openapi-generator)
*
* OpenAPI spec version: 3.0.0
* Contact: info@inexor.org
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/

#include "EntityTypeApiImpl.h"

namespace inexor {
namespace entity_system {
namespace server {
namespace api {

using namespace inexor::entity_system::server::model;

EntityTypeApiImpl::EntityTypeApiImpl(std::shared_ptr<Pistache::Rest::Router> rtr)
    : EntityTypeApi(rtr)
    { }

void EntityTypeApiImpl::create_entity_type(Pistache::Http::ResponseWriter &response) {
    response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}
void EntityTypeApiImpl::create_or_update_entity_type(const std::string &entityTypeUuid, const EntityType &entityType, Pistache::Http::ResponseWriter &response) {
    response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}
void EntityTypeApiImpl::create_or_update_entity_type_attribute(const std::string &entityTypeUuid, const std::string &name, const std::string &body, Pistache::Http::ResponseWriter &response) {
    response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}
void EntityTypeApiImpl::delete_all_instances_of_entity_type(const std::string &entityTypeUuid, Pistache::Http::ResponseWriter &response) {
    response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}
void EntityTypeApiImpl::delete_entity_type(const std::string &entityTypeUuid, Pistache::Http::ResponseWriter &response) {
    response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}
void EntityTypeApiImpl::delete_entity_type_attribute(const std::string &entityTypeUuid, const std::string &name, Pistache::Http::ResponseWriter &response) {
    response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}
void EntityTypeApiImpl::delete_entity_types(Pistache::Http::ResponseWriter &response) {
    response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}
void EntityTypeApiImpl::get_all_incoming_relationship_types_of_entity_type(const std::string &entityTypeUuid, Pistache::Http::ResponseWriter &response) {
    response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}
void EntityTypeApiImpl::get_all_instances_of_entity_type(const std::string &entityTypeUuid, Pistache::Http::ResponseWriter &response) {
    response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}
void EntityTypeApiImpl::get_all_outgoing_relationship_types_of_entity_type(const std::string &entityTypeUuid, Pistache::Http::ResponseWriter &response) {
    response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}
void EntityTypeApiImpl::get_all_relationship_types_of_entity_type(const std::string &entityTypeUuid, Pistache::Http::ResponseWriter &response) {
    response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}
void EntityTypeApiImpl::get_entity_type(const std::string &entityTypeUuid, Pistache::Http::ResponseWriter &response) {
    response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}
void EntityTypeApiImpl::get_entity_type_attribute(const std::string &entityTypeUuid, const std::string &name, Pistache::Http::ResponseWriter &response) {
    response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}
void EntityTypeApiImpl::get_entity_type_attributes(const std::string &entityTypeUuid, Pistache::Http::ResponseWriter &response) {
    response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}
void EntityTypeApiImpl::list_all_entity_types(Pistache::Http::ResponseWriter &response) {
    response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}

}
}
}
}
